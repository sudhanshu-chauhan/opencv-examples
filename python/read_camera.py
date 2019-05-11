import numpy as np
import cv2

try:
	capture_obj = cv2.VideoCapture(0)
	if capture_obj.isOpened():

		while True:
			ret, frame = capture_obj.read()
			grey_scale_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
			cv2.imshow('frame', grey_scale_frame)
			if cv2.waitKey(1) and 0xFF == ord('q'):
				break
		capture_obj.release()
		cv2.destroyAllWindows()
	else:
		print "cannot open the camera, please check your device!"

except Exception as err:
	print err.message