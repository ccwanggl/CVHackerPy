import cv2.cv2 as cv

from code_snip import rescale

img = cv.imread('../assets/earth.jpg', -1)
img_rotate = cv.rotate(img, cv.ROTATE_90_COUNTERCLOCKWISE)
cv.imshow('Image', img)
cv.imshow('Resized Image', rescale.rescaleFrame(img))
cv.imshow('Rotated Image', img_rotate)
cv.waitKey(0)
cv.destroyAllWindows()
