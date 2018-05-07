from inputs import *
import serial

ser = serial.Serial("COM3", 9600)

while 1:
    events = get_gamepad()
    for event in events:
        print(event.code, event.state)
        if event.code == "ABS_RZ":
            det = event.state
            ser.write(b'r%d' % det )
        if event.code == "ABS_Z":
            bac = event.state
            ser.write(b'b%d' % bac)
        if event.code == "ABS_X":
            dets = event.state
            ser.write(b't%d' % dets)
        if event.code == "BTN_SOUTH":
            ser.write(b's')
        if event.code == "SYN_REPORT":
            ser.write(b'c')

# ABS_Z
