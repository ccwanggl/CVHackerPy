import cv2.cv2 as cv

img = cv.imread('assets/earth.jpg', -1)
img2 = cv.resize(img,(0,0), fx=1/2, fy=1/2)
img_rotate = cv.rotate(img, cv.ROTATE_90_COUNTERCLOCKWISE)
cv.imshow('Image', img)
cv.imshow('Resized Image', img2)
cv.imshow('Rotated Image', img_rotate)
cv.waitKey(10)
cv.destroyAllWindows()
