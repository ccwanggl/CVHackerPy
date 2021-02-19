import cv2.cv2 as cv

img = cv.imread('../Resources/Photos/cats.jpg')
cv.imshow('Cats', img)

# averaging blur
average = cv.blur(img, (3, 3))
cv.imshow('Average', average)

cv.waitKey(0)
cv.destroyAllWindows()