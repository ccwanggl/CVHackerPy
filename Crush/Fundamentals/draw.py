import cv2.cv2 as cv
import numpy as np

blank = np.zeros((500, 500, 3), dtype='uint8')
cv.imshow('Blank', blank)

# Paint the image a certain color
blank[:] = 0, 0, 255
cv.imshow('Green', blank)

# 2 Draw
cv.rectangle(blank, (0, 0), (300, 400), (0, 255, 0), thickness=2)
cv.imshow('Rect', blank)

cv.rectangle(blank, (0, 0), (300, 400), (255, 255, 0), thickness=-1)
cv.imshow('Brush', blank)

cv.circle(blank, (blank.shape[1] // 2, blank.shape[0] // 2), 40, (255, 0, 0), thickness=-1)
cv.imshow('Circle', blank)

cv.line(blank, (0, 0), (blank.shape[1] // 2, blank.shape[0] // 2), (255, 255, 255), thickness=4)
cv.imshow('Line', blank)

cv.putText(blank, "Guoliang", (225, 225), cv.FONT_HERSHEY_COMPLEX, 1.0, (255, 233, 122), thickness=2)
cv.imshow("text", blank)

cv.waitKey(0)
cv.destroyAllWindows()
