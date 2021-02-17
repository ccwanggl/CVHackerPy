import cv2.cv2 as cv


img = cv.imread('../Resources/Photos/cat.jpg')
cv.imshow('Cats', img)


cv.waitKey()
cv.destroyAllWindows()