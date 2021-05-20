import cv2.cv2 as cv
import numpy as np

img = cv.imread('../Resources/Photos/Cats.jpg')
cv.imshow('Cats', img)

blank = np.zeros(img.shape[:2], "uint8")

b, g, r = cv.split(img)

blue = cv.merge([b, blank, blank])
green = cv.merge([blank, g, blank])
red = cv.merge([blank, blank, r])

cv.imshow('BlueMerged', blue)
cv.imshow('GreenMerged', green)
cv.imshow('RedMerged', red)

cv.imshow('Blue', b)
cv.imshow('Green', g)
cv.imshow('Red', r)

print(img.shape)
print(b.shape)
print(g.shape)
print(r.shape)

merged = cv.merge([b,g,r])
cv.imshow("Merged", merged)


cv.waitKey(0)
cv.destroyAllWindows()
