import cv2
from mtcnn import MTCNN

detector = MTCNN()
cap = cv2.VideoCapture(0)
if not cap.isOpened():
    print("Error opening the webcam")
else:
    ret, frame = cap.read()
    cv2.imshow('frame', frame)
    if cv2.waitKey(0) == ord('s'):
        cv2.imwrite('save.jpg', frame)
        print("Image saved")
    cap.release()
    cv2.destroyAllWindows()
    img = cv2.imread('save.jpg')
    faces = detector.detect_faces(img)
    for face in faces:
        x, y, w, h = face['box']
        cv2.rectangle(img, (x, y), (x + w, y + h), (0, 255, 0), 2)
    cv2.imshow('image', img)
    cv2.waitKey(0)
    cv2.destroyAllWindows()