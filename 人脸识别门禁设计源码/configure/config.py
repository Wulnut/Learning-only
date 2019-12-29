import os

POSITIVE_THRESHOLD = 2000.0




POSITIVE_DIR = './training/positive'
NEGATIVE_DIR = './training/negative'


POSITIVE_LABEL = 1
NEGATIVE_LABEL = 2

POSITIVE_FILE_PREFIX = 'positive_'


FACE_WIDTH  = 92
FACE_HEIGHT = 112

# base dir
BASE_DIR = os.path.abspath('./')
print BASE_DIR

HAAR_FACES         = 'haarcascade_frontalface_alt.xml'
HAAR_SCALE_FACTOR  = 1.3
HAAR_MIN_NEIGHBORS = 4
HAAR_MIN_SIZE      = (30, 30)

DEBUG_IMAGE = 'capture.pgm'


FLASH_LIGHT_PIN = 40

CLASSIFIER_FILE = BASE_DIR + '/facerec/haarcascade_frontalface_alt.xml'


FACES_DIR = BASE_DIR + '/facerec/faces'


TRAINING_DIR = BASE_DIR + '/facerec/training'


TRAINING_FILE = TRAINING_DIR + '/training.xml'

USERS_CVS_FILE = BASE_DIR + '/facerec/training/users.csv'
