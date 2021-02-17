import cv2.cv2 as cv

img = cv.imread('../Resources/Photos/cat.jpg')
cv.imshow('Cat', img)


# Converting to grayscale
gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
cv.imshow("Gray", gray)

# Blur

blur = cv.GaussianBlur(img, (3,3), cv.BORDER_DEFAULT)
cv.imshow("Blur", blur)


cv.waitKey(0)
cv.destroyAllWindows()
