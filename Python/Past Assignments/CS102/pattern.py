# Name:        Taidgh Murray
# Student ID:  15315901

# File:        pattern.py

############################################################################

import graphics

win = graphics.GraphWin()

for a in range(0,20):
    i=a
    for b in range(0,20):
        j=b
        circpoint=graphics.Point(10*(i)+5,10*(j)+5)
        repeat=graphics.Circle(circpoint, 4)
        repeat.setFill('Lime Green')
        repeat.draw(win)


# this waits until you have clicked in the window to close it.
win.getMouse()
win.close()
