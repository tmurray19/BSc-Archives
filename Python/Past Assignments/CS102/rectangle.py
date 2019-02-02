# Name:        Taidgh Murray
# Student ID:  15315901

# File:        rectangle.py

############################################################################

import graphics

win = graphics.GraphWin("Rectangle", 200,200)
p1= win.getMouse()
p2= win.getMouse()
rectangle=graphics.Rectangle(p1, p2)
rectangle.setOutline('Black')
rectangle.setFill('Light Blue')
rectangle.draw(win)

anchor1= graphics.Point(110,10)
anchor2= graphics.Point(110,180)
Text1 = graphics.Text(anchor1, ("The area of the rectangle is" , (p2.getX() - p1.getX()) * (p2.getY() - p1.getY())))
Text1.setSize(8)
Text1.draw(win)
Text2 = graphics.Text(anchor2, ("The perimeter of the rectange is" , 2*(p2.getX() - p1.getX()) + 2*(p2.getY() - p1.getY())))
Text2.setSize(7)
Text2.draw(win)
# this waits until you have clicked in the window to close it.
win.getMouse()
win.close()
