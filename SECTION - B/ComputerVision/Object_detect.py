import cv2  
import numpy as np

# Store original image in matrix and converting it into HSV format
original_image = cv2.imread("abhiyaan_opencv_qn1.png")
hsv_original = cv2.cvtColor(original_image, cv2.COLOR_BGR2HSV)

# Store Region of interest image in matrix and converting it into HSV format
roi = cv2.imread("orange_whiteobj.png")
hsv_roi = cv2.cvtColor(roi, cv2.COLOR_BGR2HSV)


# Histogram ROI
roi_hist = cv2.calcHist([hsv_roi], [0, 1], None, [180, 256], [0, 180, 0, 256])
mask = cv2.calcBackProject([hsv_original], [0, 1], roi_hist, [0, 180, 0, 256], 1)

# Filtering remove noise
kernel = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (5,5))
dst = cv2.filter2D(mask, -1, kernel)
ret, dst = cv2.threshold(dst, 100, 255, cv2.THRESH_BINARY)

# Finding contours in the Thresholded image and drawing boxes around original image
contours, _ = cv2.findContours(dst, cv2.RETR_LIST, cv2.CHAIN_APPROX_SIMPLE)
for c in contours:
    rect = cv2.boundingRect(c)
    x,y,w,h = rect
    cv2.rectangle(original_image,(x,y),(x+w,y+h),(0,255,0),2)

# Displaying original image with boxes around the obstacle 
cv2.imshow("obj_detect",original_image)

# Waits till user presses any key
cv2.waitKey(0)  
