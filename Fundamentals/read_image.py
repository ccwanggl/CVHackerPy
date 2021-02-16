import cv2.cv2 as cv


def rescaleFrame(frame, scale=0.75):
    width = int(frame.shape[1] * scale)
    height = int(frame.shape[0] * scale)

    dimensions = (width, height)
    return cv.resize(frame, dimensions, interpolation=cv.INTER_AREA)


img = cv.imread('../assets/earth.jpg', -1)
img_rotate = cv.rotate(img, cv.ROTATE_90_COUNTERCLOCKWISE)
cv.imshow('Image', img)
cv.imshow('Resized Image', rescaleFrame(img))
cv.imshow('Rotated Image', img_rotate)
cv.waitKey(0)
cv.destroyAllWindows()
