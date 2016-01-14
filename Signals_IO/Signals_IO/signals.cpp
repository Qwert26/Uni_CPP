#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
//#define DEBUG
enum SignalType { WLAN, BLUETOOTH };
/**
* @brief The Signal class represents a captured signal
*/
class Signal {
private:
	SignalType type;
	std::string deviceId;
	int strength;
	unsigned channel;
public:
	Signal() : type(WLAN) {}
	SignalType getType() const { return type; }
	void setType(SignalType _type) { this->type = _type; }
	std::string getDeviceId() const { return deviceId; }
	void setDeviceId(std::string _deviceId) { this->deviceId = _deviceId; }
	int getStrength() const { return strength; }
	void setStrength(int _strength) { this->strength = _strength; }
	unsigned getChannel() const { return channel; }
	void setChannel(unsigned _channel) { this->channel = _channel; }

	friend std::ostream& operator<<(std::ostream& output,const Signal& signal) {
		if (signal.type == WLAN) {
			output << "WLAN, ";
		} else if (signal.type == BLUETOOTH) {
			output << "BLUETOOTH, ";
		} else {
			//Ein illegaler SignalType wurde verwendet!
			return output;
		}
		output << signal.deviceId << ", ";
		output << signal.strength << ", " << signal.channel;
		return output;
	}
	friend std::istream& operator>>(std::istream& input,Signal& signal) {
		char buffer[12];
		input.getline(buffer, 12, ',');
		#ifdef DEBUG
		std::cout << buffer << std::endl;
		#endif
		std::string look(buffer);
		if (look.compare("WLAN") == 0) {
			signal.type = WLAN;
		} else {
			signal.type = BLUETOOTH;
		}
		input >> signal.deviceId;
		signal.deviceId.erase(signal.deviceId.end()-1);
		#ifdef DEBUG
		std::cout << signal.deviceId << std::endl;
		#endif
		input.ignore(1);
		input >> signal.strength;
		input.ignore(2);
		input >> signal.channel;
		return input;
	}
};
//TODO: provide implementations of the overloaded I/O operators
std::vector<Signal> readSignals(const char* filepath) {
	std::ifstream in(filepath);
	Signal s;
	std::vector<Signal> ret;
	while (!in.eof() && in>>s) {
		//Was haben wir eingelesen?
		#ifdef DEBUG
		std::cout << s << std::endl;
		#endif
		ret.push_back(Signal(s));
		//Gehe in die nächste Zeile.
		in.ignore();
	}
	return ret;
}
std::vector<Signal> filterSignals(SignalType type, std::vector<Signal>& signalReadings) {
	std::vector<Signal> ret;
	const size_t l = signalReadings.size();
	for (size_t i = 0; i < l; ++i) {
		if (signalReadings[i].getType() == type) {
			ret.push_back(signalReadings[i]);
		}
	}
	return ret;
}
void writeSignals(const char* outputFilename, const std::vector<Signal> aggregatedSignals) {
	std::ofstream out(outputFilename);
	const size_t l = aggregatedSignals.size();
	for (size_t i = 0; i < l;++i) {
		out << aggregatedSignals[i]<<std::endl;
	}
}
int main(void) {
	const char * filename = "signals.txt";
	std::vector<Signal> rawSignals = readSignals(filename);
	std::vector<Signal> filteredSignals = filterSignals(WLAN, rawSignals);

	std::cout << rawSignals.size() << " signals were read, of which "
		<< filteredSignals.size() << " were WLAN signals!"
		<< std::endl;

	writeSignals("filtered_signals.txt", filteredSignals);
	return 0;
}