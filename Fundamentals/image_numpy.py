import cv2.cv2 as cv
import random

img = cv.imread('../assets/earth.jpg', -1)

earth = img[200:800, 600:1300]
img[0:600, 0:700] = earth

cv.imshow('Earth', img)
cv.waitKey(0)
cv.destroyAllWindows()

