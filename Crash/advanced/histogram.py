import cv2.cv2 as cv
import numpy as np
import matplotlib.pyplot as plt

img = cv.imread('../Resources/Photos/cats.jpg')
cv.imshow('Cats', img)

blank = np.zeros(img.shape[:2], dtype='uint8')

gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
cv.imshow('Gray', gray)

circle = cv.circle(blank, (img.shape[1]//2, img.shape[0]//2), 100, 255, -1)

mask = cv.bitwise_and(gray, gray, mask=circle)
cv.imshow('Mask', mask)


gray_hist = cv.calcHist([gray], [0], mask, [256], [0, 255])

plt.figure()
plt.title('Color Histogram')
plt.xlabel('Bins')
plt.ylabel('# of pixels')

colors = ('b', 'g', 'r')
for i, col in enumerate(colors):
    hist = cv.calcHist([img], [i], None, [255], [0, 255])
    plt.plot(hist, color=col)
    plt.xlim([0, 255])

plt.show()

cv.waitKey(0)
cv.destroyAllWindows()