import cv2.cv2 as cv


img = cv.imread('../Resources/Photos/cats.jpg')
cv.imshow('Cats', img)

gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
cv.imshow('Gray', gray)


cv.waitKey()
cv.destroyAllWindows()