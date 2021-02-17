import cv2.cv2 as cv
from code_snip import rescale

capture = cv.VideoCapture(0)

while True:
    isTrue, frame = capture.read()
    cv.imshow('Video', frame)
    cv.imshow('Recaled Video', rescale.rescaleFrame(frame, .2))

    if cv.waitKey(0) & 0xFF == ord('d'):
        break

capture.release()
cv.destroyAllWindows()