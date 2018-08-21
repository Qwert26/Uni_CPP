def lcg(seed,mult,add,mod):
        while True:
            seed=(seed*mult+add)%mod
            yield seed
r=lcg(4,71,72,100)
for i in range(11):
    print(next(r))