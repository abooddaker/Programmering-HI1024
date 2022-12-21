# Decline cookies script

# Import the webdriver module and the necessary classes
from selenium import webdriver
from selenium.webdriver.common.by import By

# Create a new Chrome webdriver
driver = webdriver.Chrome()

# Get the URL of the current website
url = driver.current_url

# Open the website you want to visit
driver.get(url)

# Wait for the cookie banner to appear
driver.implicitly_wait(10)

# Find the "Decline" button and click it
decline_button = driver.find_element(By.XPATH, "//button[text()='Decline']")
decline_button.click()

# Close the webdriver
driver.quit()
