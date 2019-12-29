#coding=utf-8

import face
from configure import config

import cv2
import os
import sys
import glob

def capture(personName):
    PERSON_DIR = config.POSITIVE_DIR + '/' + personName
    camera = None
    if not os.path.exists(config.POSITIVE_DIR):
        os.mkdir(config.POSITIVE_DIR)
    if not os.path.exists(PERSON_DIR):
        os.mkdir(PERSON_DIR)
    files = sorted(glob.glob(os.path.join(PERSON_DIR,
        config.POSITIVE_FILE_PREFIX + personName + '_' + '[0-9][0-9][0-9].pgm')))
    count = 0
    if len(files) > 0:
        count = int(files[-1][-7:-4])+1
    
    image = camera.read()
    image = cv2.cvtColor(image, cv2.COLOR_RGB2GRAY)
    result = face.detectSingleFace(image)
    if result is None:
        print 'Could not detect single face!'
        return
    x, y, w, h = result
    crop = face.crop(image, x, y, w, h)
    filename = os.path.join(PERSON_DIR, config.POSITIVE_FILE_PREFIX + personName + '_' + '%03d.pgm' % count)
    cv2.imwrite(filename, crop)
    
    