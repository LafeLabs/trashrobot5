
unit = 100
numSteps = unit

mainglyph = "0101,0300,0400,0404,0300,0501,"
bytecode = [
        "0500:0400,0402,0401,0403,",
        "0501:0407,0407,0500,"
        ]

hypercube = []
for index in range(1024):
    hypercube.append("")

for row in bytecode:
    splitrow = row.split(":")
    if len(splitrow) > 0:
        address = int(splitrow[0],8)
        hypercube[address] = splitrow[1]


def action(address):
    #address is an integer, an index in the Hypercube
    if address == 0o400:
        print("move left numSteps")
    if address == 0o401:
        print("move right numSteps")
    if address == 0o402:
        print("move in numSteps")
    if address == 0o403:
        print("move out numSteps")
    if address == 0o0404:
        print("move up numSteps")
    if address == 0o0405:
        print("move down numSteps")
    if address == 0o0406:
        print("numSteps /= 2")
    if address == 0o0407:
        print("numSteps *= 2")

def sequence(glyph):
    #glyph is a string which is a comma delimited array of base 8 numbers in js notation
    glyphArray = glyph.split(",")
    for addressstring in glyphArray:
        #print(addressstring)
        if len(addressstring) > 0:
            address = int(addressstring,8)
            #print(address)
            if address >= 0o400 and address < 0o500:
              action(address)
            if address >= 0o500 and address < 0o600:
              sequence(hypercube[address])

            
sequence(mainglyph)