import cv2.cv2 as cv

img = cv.imread('../Resources/Photos/cat.jpg')
cv.imshow('Cat', img)


cv.waitKey(0)
cv.destroyAllWindows()
