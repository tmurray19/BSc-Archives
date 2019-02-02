# Name:        Taidgh Murray
# Student ID:  15315901

# File:        sphere.py

############################################################################
global r


def sphereArea(radius):
	return (radius**2*4*3.1415)
		
def sphereVolume(radius):
	return (4/3*3.1415*radius**3)
	
def main():
	r=abs(int(input("Please enter the radius: ")))
	print("The area of the sphere is: ", sphereArea(r))
	print("The volume of the sphere is: ", sphereVolume(r))
	
main()
	
