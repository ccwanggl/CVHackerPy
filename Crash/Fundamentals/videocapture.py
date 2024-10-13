import cv2.cv2 as cv
from code_snip import rescale
from code_snip import resize_live_video

capture = cv.VideoCapture(0)
resize_live_video.changeRes(100, 200, capture)

while True:
    isTrue, frame = capture.read()
    cv.imshow('Video', frame)
    # cv.imshow('Recaled Video', rescale.rescaleFrame(frame, .2))

    if cv.waitKey(20) & 0xFF == ord('d'):
        break

capture.release()
cv.destroyAllWindows()