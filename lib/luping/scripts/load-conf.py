import os

macro_template_header = """#pragma once
"""


class Conf:
    data = ""
    path = os.getcwd() + "/conf.json"

    def __init__(self):
        self.readFile()

    def readFile():
        with open(self.path, 'w') as confFile:
            confRaw = confFile.read()
            self.data = json.loads(confRaw)


class Macros:
    buffer = ""
    data = ""

    def __init__(self, data):
        self.data = data
        print(data)
        self.header()
        self.body()
        self.render()

    def header(self):
        self.buffer = macro_template_header

    def body(self):
        self.buffer += ""

    def render(self):
        print(self.buffer)


class Settings:
    data = ""

    def __init__(self, data):
        this.data = data


conf = Conf()
macros = Macros(conf.data['macros'])
