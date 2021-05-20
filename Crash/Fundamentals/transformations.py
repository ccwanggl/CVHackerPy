import cv2.cv2 as cv
import numpy as np

img = cv.imread('../Resources/Photos/cat.jpg')
cv.imshow('Cat', img)


# Translation
def translate(frame, x, y):
    # -x --> left
    # -y --> Up
    # x --> Right
    # y --> Down

    transMat = np.float32([[1, 0, x], [0, 1, y]])
    dimensions = (frame.shape[1], frame.shape[0])
    return cv.warpAffine(img, transMat, dimensions)


translated = translate(img, 100, 100)
cv.imshow('Translated image', translated)


# Rotation
def rotate(frame, angle, rotPoint=None):
    (height, width) = frame.shape[:2]

    if rotPoint is None:
        rotPoint = (width / 2, height / 2)

    rotMat = cv.getRotationMatrix2D(rotPoint, angle, 1.0)
    dimensions = (width, height)
    return cv.warpAffine(frame, rotMat, dimensions)


rotated = rotate(img, 45)
cv.imshow('Rotated image', rotated)

# Resize
resized = cv.resize(img, (500, 500), interpolation=cv.INTER_CUBIC)
cv.imshow('Resized', resized)

# Flipping
flip = cv.flip(img, 0)
cv.imshow('Flip', flip)


cv.waitKey(0)
cv.destroyAllWindows()
