def raw_2_dict(raw_file: str) -> dict[str, str]: 
    with open(raw_file, 'r', encoding="utf8") as file:
        raw= file.read()
        
        _item= dict(line.split("...") for line in raw.split("\n") if line != "")

        rs= dict((y, int(x)) for x, y in _item.items())

    return rs # item_name: id

def id_g3_g1(g1: dict, g3: dict) -> dict:
    rs= dict()
    g3= {k: v for k, v in sorted(g3.items(), key=lambda item: item[1])}
    for k, v in g3.items(): # key = name of item
        # id of item gen 3 (v) = id of item gen 1 (g1[k])
        # if gen 1 doesnt has that item: id=0
        try:
            rs[v] = g1[k]
        except KeyError:
            rs[v] = 0

    return rs # {id_gen3: id_gen1}

def convert_to_cdict(g3_g1: dict) -> str:
    rs= str()
    for g3, g1 in g3_g1.items():
        new= {g3: g1}
        rs+= str(new) + ",\n"

    return rs[0:-2] # str( {g3, g1}, ...)

def make_it_be_array(di: dict) -> list: # 0 -> 374 if id not found in gen1 or gen3 the value will be set to 0
    rs= list()
    for i in range(1,375):
        try:
            g1id= di[i]
            rs.append(g1id)
        except KeyError:
            rs.append(0)
    return rs # [idg1, idg1, idg1, idg1,...]

if __name__ == "__main__":
    item_g1= raw_2_dict("item_gen1.txt")
    item_g3= raw_2_dict("item_gen3.txt")

    rs= id_g3_g1(item_g1, item_g3)
    

    # finalRs= make_it_be_array(rs)
    # print(str(finalRs))

    # final_rs = convert_to_cdict(rs)

