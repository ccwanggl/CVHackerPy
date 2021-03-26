import cv2.cv2 as cv


def rescaleFrame(frame, scale=0.75):
    # image, live video
    width = int(frame.shape[1] * scale)
    height = int(frame.shape[0] * scale)

    dimensions = (width, height)

    return cv.resize(frame, dimensions, interpolation=cv.INTER_AREA)
