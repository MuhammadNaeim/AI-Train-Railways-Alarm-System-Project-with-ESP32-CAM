import cv2
import urllib.request
import numpy as np

# Replace the URL with the IP address of your ESP32 Cam
url = 'http://192.168.1.13:81/stream'

# Open a connection to the video stream
stream = urllib.request.urlopen(url)

# Read the first frame from the stream
bytes = bytes()
while True:
    bytes += stream.read(1024)
    a = bytes.find(b'\xff\xd8')
    b = bytes.find(b'\xff\xd9')
    if a != -1 and b != -1:
        jpg = bytes[a:b+2]
        bytes = bytes[b+2:]
        frame = cv2.imdecode(np.fromstring(jpg, dtype=np.uint8), cv2.IMREAD_COLOR)
        break

# Initialize the tracker
tracker = cv2.TrackerKCF_create()

# Select the ROI in the first frame
bbox = cv2.selectROI('frame', frame, False)
tracker.init(frame, bbox)

# Loop through the video stream
while True:
    # Read the next frame from the stream
    bytes += stream.read(1024)
    a = bytes.find(b'\xff\xd8')
    b = bytes.find(b'\xff\xd9')
    if a != -1 and b != -1:
        jpg = bytes[a:b+2]
        bytes = bytes[b+2:]
        frame = cv2.imdecode(np.fromstring(jpg, dtype=np.uint8), cv2.IMREAD_COLOR)

    # Update the tracker
    ok, bbox = tracker.update(frame)
    if ok:
        # Draw the bounding box around the tracked object
        x, y, w, h = [int(v) for v in bbox]
        cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 255, 0), 2)
    else:
        # Object lost, re-initialize the tracker
        bbox = cv2.selectROI('frame', frame, False)
        tracker.init(frame, bbox)

    # Display the frame
    cv2.imshow('frame', frame)
    if cv2.waitKey(1) == ord('q'):
        break

# Release the resources
stream.release()
cv2.destroyAllWindows()