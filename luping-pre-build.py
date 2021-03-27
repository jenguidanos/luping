import json

buffer = ""
confRaw = ""
conf = ""

def init():
    loadConfJson()
    fileHeader()
    fileBody()
    parseConf()
    fileFooter()

def fileHeader():
    global buffer
    buffer += """#pragma once
// DO NOT EDIT THIS FILE, IT IS AUTO GENERATED.
// SEE conf.json AT THE PROJECT ROOT

struct Conf {"""


def fileFooter():
    global buffer
    buffer += "} // end struct Conf"

def fileBody():
    for prop in conf:
        print(prop)

def loadConfJson():
    global confRaw, conf
    with open('conf.json', 'r') as confFile:
        confRaw = confFile.read()
        conf = json.loads(confRaw)

def parseConf():
    if len(buffer):
        f = open("src/conf.h", "w")
        f.write(buffer)
        f.close()

init()