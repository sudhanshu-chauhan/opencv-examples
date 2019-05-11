import sys

import numpy as np
import cv2


try:
	if len(sys.argv) > 1:
		video_capture_obj = cv2.VideoCapture(sys.argv[1])

		while video_capture_obj.isOpened():
			ret, frame = video_capture_obj.read()
			gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
			cv2.imshow('frame', gray)

			if cv2.waitKey(1) and 0xFF == ord('q'):
				break
		video_capture_obj.release()
		cv2.destroyAllWindows()

except Exception as err:
	print err.message