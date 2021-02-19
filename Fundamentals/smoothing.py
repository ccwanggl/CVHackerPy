import cv2.cv2 as cv

img = cv.imread('../Resources/Photos/cats.jpg')
cv.imshow('Cats', img)

# averaging blur
average = cv.blur(img, (3, 3))
cv.imshow('Average Blur', average)

# guess blur
gauss = cv.GaussianBlur(img, (3, 3), 0)
cv.imshow("Gauess", gauss)


# Median blur
median = cv.medianBlur(img, 3)
cv.imshow("Median", median)



cv.waitKey(0)
cv.destroyAllWindows()