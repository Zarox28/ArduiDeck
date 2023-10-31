# ----- LIBRARY IMPORTATION -----
import time
import serial
import os
import sys
from pyfiglet import Figlet

# ----- FIGLET -----
f = Figlet(font="slant")
print(f.renderText("ArduiDeck"))

# ----- VARIABLES -----
connected = False
port = open("src/port.txt", "r").read()

# ----- SERIAL -----
while connected == False:
    if os.system("ls {} > /dev/null 2>&1".format(port)) == 0:
        print("ArduiDeck connected !")
        print("")
        arduino = serial.Serial(port, 9600, timeout=.1)
        time.sleep(0.5)
        arduino.write(bytes("i", "utf-8"))
        connected = True
    else:
        connected = False

    time.sleep(0.5)

# ----- LOOP -----
while connected == True:
    try:
        data = arduino.readline()[:-2]

    except:
        print("")
        print("ArduiDeck disconnected !")
        print("")
        print("---------------")
        print("Auto-reconnecting ...")
        print("---------------")
        print("")

        os.execl(sys.executable, sys.executable, *sys.argv)

    if data:
        data = str(data, "utf-8")

        # ----- COMMON APPS -----

        if data == "spark":
            os.system("open -a arc")

        if data == "system_preferences":
            os.system("open -a system\ preferences")

        if data == "spark":
            os.system("open -a spark")

        if data == "messages":
            os.system("open -a messages")

        if data == "music":
            os.system("open -a music")

        if data == "photos":
            os.system("open -a photos")

        if data == "reminders":
            os.system("open -a reminders")

        if data == "calendar":
            os.system("open -a calendar")

        if data == "discord":
            os.system("open -a disccord")

        if data == "remarkable":
            os.system("open -a remarkable")

        # ----- DEV APPS -----

        if data == "terminal":
            os.system("open -a iterm")

        if data == "vscode":
            os.system("open -a Visual\ Studio\ Code")

        if data == "source_tree":
            os.system("open -a sourcetree")

        if data == "arduino":
            os.system("open -a arduino")

        if data == "textmate":
            os.system("open -a textmate")

        if data == "termius":
            os.system("open -a termius")

        if data == "postman":
            os.system("open -a postman")

        if data == "devdocs":
            os.system("open -a devdocs")

        if data == "diskutility":
            os.system("open -a Disk\ Utility")

        if data == "resmon":
            os.system("open -a Activity\ Monitor")

        # ----- SCRIPTS -----

        if data == "speedtest":
            print("")
            os.system("./src/scripts/speedtest-cli")
            print("")

        if data == "myip":
            print("")
            os.system("curl http://ipecho.net/plain; echo")
            print("")

        if data == "clear":
            os.system("clear")
            print(f.renderText("ArduiDeck"))

        if data == "lock":
            os.system("osascript src/scripts/lock.applescript")

        if data == "disconnect":
            print("")
            print("ArduiDeck disconnected !")
            os.system("killall Terminal")
