import cv2
import numpy as np

cap  = cv2.VideoCapture(0)

while True:
	res,frame = cap.read()
	if res:
		cv2.imshow(frame)
		if cv2.waitKey(1) & 0xff == ord('q'):
			break

cap.release()
cv2.destroyAllWindows() 

'''
import numpy as np
import cv2

cap = cv2.VideoCapture(0)
 
while(True):
    ret, frame = cap.read()
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
 
    cv2.imshow('frame',gray)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
'''