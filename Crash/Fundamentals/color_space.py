import cv2.cv2 as cv
import numpy as np
import matplotlib.pyplot as plt

img = cv.imread('../Resources/Photos/cats.jpg')
cv.imshow('Cats', img)

#plt.imshow(img)
#plt.show()


gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
cv.imshow('Gray', gray)


hsv = cv.cvtColor(img, cv.COLOR_BGR2HSV)
cv.imshow('HSV', hsv)

lab = cv.cvtColor(img, cv.COLOR_BGR2LAB)
cv.imshow('LAB', lab)

rgb = cv.cvtColor(img, cv.COLOR_BGR2RGB)
cv.imshow('RGB', rgb)

plt.imshow(rgb)
plt.show()

cv.waitKey(0)
cv.destroyAllWindows()