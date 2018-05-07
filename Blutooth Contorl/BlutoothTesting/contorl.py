import serial

ser = serial.Serial('COM4', 38400)
while 1:
    state = input("Type o to turn on the LED type f to turn off the LED")
    if state == 'o':
        on = 1
        ser.write(b's%d' % on)
    if state == 'f':
        off = 0
        ser.write(b's%d' % off)
