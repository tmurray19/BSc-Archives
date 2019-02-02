# Name:        Taidgh Murray
# Student ID:  15315901

# File:        archery.py

############################################################################

import graphics

win = graphics.GraphWin('Archery Target')

point=graphics.Point(100,100)


Targetwhite=graphics.Circle(point, 50)
Targetwhite.setFill('White')
Targetwhite.draw(win)

Targetblack=graphics.Circle(point, 40)
Targetblack.setFill('Black')
Targetblack.draw(win)

Targetblue=graphics.Circle(point, 30)
Targetblue.setFill('Blue')
Targetblue.draw(win)

Targetred=graphics.Circle(point, 20)
Targetred.setFill('Red')
Targetred.draw(win)

Targetyellow=graphics.Circle(point, 10)
Targetyellow.setFill('Yellow')
Targetyellow.draw(win)
# this waits until you have clicked in the window to close it.
win.getMouse()
win.close()
