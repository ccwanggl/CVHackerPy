import cv2.cv2 as cv

img = cv.imread('../Resources/Photos/cats.jpg')
cv.imshow('Cats', img)


cv.waitKey(0)
cv.destroyAllWindows()