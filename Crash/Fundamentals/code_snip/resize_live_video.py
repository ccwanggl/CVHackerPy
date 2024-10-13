
def changeRes(width, height, capture):
    # Live video
    capture.set(3, width)
    capture.set(4, height)
