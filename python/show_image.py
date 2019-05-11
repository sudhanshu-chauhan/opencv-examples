import numpy as np
import cv2


try:
	img = cv2.imread("/home/sud/Pictures/blur.png", 0)
	cv2.imshow("image", img)
	k = cv2.waitKey(0)
	if k == 27:
		cv2.destroyAllWindows()
	elif k == ord('s'): #wait for 's' key to save and exit
		cv2.imwrite("/home/sud/testing.png", img)
		cv2.destroyAllWindows()
except Exception as err:
	print err.message

