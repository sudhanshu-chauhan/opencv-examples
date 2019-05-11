import numpy as np
import cv2


try:
	img = cv2.imread("/home/sud/Pictures/blur.png", 0)
	cv2.rectangle(img, (0, 0), (511, 511), (0, 255, 0), 3)
	cv2.imshow("image", img)
	key = cv2.waitKey(0)

except Exception as err:
	print err.message