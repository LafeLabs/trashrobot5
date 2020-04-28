import json

f = open("data/json3d.txt", "r")
json3d = json.loads(f.read())

unit = 100
numSteps = unit

bytecode = json3d["shapes"]
mainglyph = json3d["glyph"]

#mainglyph = "0101,0300,0400,0404,0300,0501,"
#bytecode = [
#        "0500:0400,0402,0401,0403,",
#        "0501:0407,0407,0500,"
#        ]

hypercube = []
for index in range(1024):
    hypercube.append("")

for row in bytecode:
    splitrow = row.split(":")
    if len(splitrow) > 0:
        address = int(splitrow[0],8)
        hypercube[address] = splitrow[1]

def moveLeft(x):
    print("move left " + str(x))
def moveRight(x):
    print("move right " + str(x))
def moveIn(x):
    print("move in " + str(x))
def moveOut(x):
    print("move out " + str(x))
def moveUp(x):
    print("move up " + str(x))
def moveDown(x):
    print("move down " + str(x))


def action(address):
    global numSteps
    #address is an integer, an index in the Hypercube
    if address == 0o400:
        moveLeft(numSteps)
    if address == 0o401:
        moveRight(numSteps)
    if address == 0o402:
        moveIn(numSteps)
    if address == 0o403:
        moveOut(numSteps)
    if address == 0o0404:
        moveUp(numSteps)
    if address == 0o0405:
        moveDown(numSteps)
    if address == 0o0406:
        numSteps /= 2
    if address == 0o0407:
        numSteps *= 2
        
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

            
sequence("0500,0407,0407,0500,0407,0407,0500,")