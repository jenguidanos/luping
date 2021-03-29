import os
import json

macro_filepath = "./"
macro_tpl = """#pragma once

// DO NOT EDIT THIS FILE, IT IS AUTO GENERATED.
// SEE conf.json AT THE PROJECT ROOT

%macros%"""

conf_h_tpl = """#pragma once

// CAUTION! DO NOT EDIT THIS FILE
// This is an autogenerated file. Please see conf.json at project root

namespace lp {

%structs%
struct LupingConf {
%objects%};

extern LupingConf conf;

void initConf();

}  // namespace lp

"""

conf_cpp_tpl = """#include "luping-conf.h"

// CAUTION! DO NOT EDIT THIS FILE
// This is an autogenerated file. Please see conf.json at project root

namespace lp {

struct LupingConf conf;

%structs%
void initConf() {
  conf = {%constructor%};
}

}  // namespace lp

"""

module_h_tpl = """#pragma once

// CAUTION! DO NOT EDIT THIS FILE
// This is an autogenerated file. Please see conf.json at project root

%structs%
namespace lp {
void customModules();
}  // namespace lp

"""

module_c_tpl = """#include "modules.h"

#include "luping.h"

%structs%
namespace lp {

void customModules() {
%modules%}

}  // namespace lp

"""


class ConfJson:
    data = ""
    path = os.getcwd() + "/conf.json"

    def __init__(self):
        self.readFile()

    def readFile(self):
        with open(self.path, 'r') as confFile:
            confRaw = confFile.read()
            self.data = json.loads(confRaw)


class Macros:
    buffer = ""
    path = os.getcwd() + "/lib/luping/include/macros.h"

    def __init__(self, data):
        self.render(data)
        self.crateFile()

    def render(self, data):
        for prop in data:
            self.buffer += f'#define {prop} {data[prop]}\n'

    def crateFile(self):
        fileData = macro_tpl.replace("%macros%", self.buffer)
        file = open(self.path, "w")
        file.write(fileData)
        file.close()


class Conf:
    hbuffer = ""
    hobjects = ""
    cbuffer = ""
    hpath = os.getcwd() + "/lib/luping/src/conf/luping-conf.h"
    cpath = os.getcwd() + "/lib/luping/src/conf/luping-conf.cpp"

    def __init__(self, data):
        self.renderHeader(data)
        self.renderCpp(data)
        self.createFiles()

    def parseProp(self, prop, value):
        dic = {'type': 'UNKNOW', 'name': 'UNKNOW', 'value': 'UNKNOW'}
        if type(value) is int:
            dic['type'] = 'int'
            dic['name'] = prop
            dic['value'] = value
        elif type(value) is float:
            dic['type'] = 'float'
            dic['name'] = prop
            dic['value'] = value
        elif type(value) is bool:
            dic['type'] = 'bool'
            dic['name'] = prop
            dic['value'] = str(value).lower()
        else:
            size = len(value) + 1
            dic['type'] = 'char'
            dic['name'] = f'{prop}[{str(size)}]'
            dic['value'] = f'{{ "{value}" }}'
        return dic

    def renderStructConf(self, confName, conf):
        buffer = ""
        for prop in conf:
            dic = self.parseProp(prop, conf[prop])
            buffer += f'  {dic.get("type")} {dic.get("name")} = {dic.get("value")};' + '\n'
        return buffer

    def renderHeader(self, data):
        buffer = ""
        for prop in data:
            buffer += f"struct {prop.capitalize()}Conf {{" + '\n'
            buffer += self.renderStructConf(prop, data[prop])
            buffer += '};\n\n'
            self.hobjects += f'  {prop.capitalize()}Conf {prop};\n'

        self.hbuffer += buffer

    def renderCpp(self, data):
        structs = ""
        constructor = []
        c = ", "
        for prop in data:
            structs += f'struct {prop.capitalize()}Conf {prop}Conf;\n'
            constructor.append(f'{prop}Conf')

        self.cbuffer = conf_cpp_tpl.replace("%structs%", structs)
        self.cbuffer = self.cbuffer.replace(
            "%constructor%", c.join(constructor))

    def createFiles(self):
        header = conf_h_tpl.replace("%structs%", self.hbuffer)
        header = header.replace("%objects%", self.hobjects)
        cpp = self.cbuffer

        hFile = open(self.hpath, "w")
        hFile.write(header)
        hFile.close()

        cFile = open(self.cpath, "w")
        cFile.write(cpp)
        cFile.close()


class Modules:
    hbuffer = ""
    cbuffer = ""
    cstruct = ""
    hpath = os.getcwd() + "/lib/luping/src/modules.h"
    cpath = os.getcwd() + "/lib/luping/src/modules.cpp"

    def __init__(self, data):
        self.renderHeader(data)
        self.renderCpp(data)
        self.crateFile()

    def renderHeader(self, data):
        for prop in data:
            self.hbuffer += (
                f'#include "{prop}.h"\n'
                f'extern {prop.capitalize()}Module *{prop};\n'
            )

    def renderCpp(self, data):
        for prop in data:
            self.cbuffer += f'  lp::modules.add({prop});\n'
            self.cstruct += (
                f'{prop.capitalize()}Module *{prop};\n'
            )

    def crateFile(self):
        header = module_h_tpl.replace("%includes%", self.hbuffer)
        header = header.replace("%structs%", self.hbuffer)
        hFile = open(self.hpath, "w")
        hFile.write(header)
        hFile.close()

        cpp = module_c_tpl.replace("%modules%", self.cbuffer)
        cpp = cpp.replace("%structs%", self.cstruct)
        cFile = open(self.cpath, "w")
        cFile.write(cpp)
        cFile.close()


confJson = ConfJson()
Macros(confJson.data['macros'])
Conf(confJson.data['settings'])
Modules(confJson.data['modules'])
