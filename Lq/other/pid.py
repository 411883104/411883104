'''
Author       : Outsider
Date         : 2023-03-21 11:17:42
LastEditors  : Outsider
LastEditTime : 2023-03-21 11:17:49
Description  : In User Settings Edit
FilePath     : \Lq\other\pid.py
'''
import math

# Path and speed constraints
path_length = 10.0 # meters
max_speed = 2.0 # meters per second
max_acceleration = 1.0 # meters per second squared

# PID controller gains
kp = 1.0
ki = 0.0
kd = 0.0

# Trajectory planning parameters
dt = 0.1 # seconds
total_time = 10.0 # seconds
num_steps = int(total_time / dt)

# Calculate distance and heading between start and end points
dx = end_x - start_x
dy = end_y - start_y
distance = math.sqrt(dx*dx + dy*dy)
heading = math.atan2(dy, dx)

# Initialize position and velocity
x = start_x
y = start_y
speed = 0.0

# Initialize PID controller
error_sum = 0.0
last_error = 0.0

# Initialize trajectory planner
trajectory = []
for i in range(num_steps):
    t = float(i) / float(num_steps - 1)
    s = t * path_length
    v = max_speed * t
    trajectory.append((s, v))

# Main loop
for i in range(num_steps):
    # Get current position along trajectory
    s, v = trajectory[i]

    # Calculate error between current position and desired position
    error = s - distance

    # Integrate error and calculate derivative
    error_sum += error * dt
    error_diff = (error - last_error) / dt
    last_error = error

    # Calculate control output using PID gains
    control = kp * error + ki * error_sum + kd * error_diff

    # Calculate desired speed
    desired_speed = min(max_speed, max(0.0, v + control))

    # Calculate desired acceleration
    desired_acceleration = (desired_speed - speed) / dt

    # Limit acceleration
    desired_acceleration = min(max_acceleration, max(-max_acceleration, desired_acceleration))

    # Update speed and position
    speed += desired_acceleration * dt
    speed = min(max_speed, max(0.0, speed))
    x += speed * math.cos(heading) * dt
    y += speed * math.sin(heading) * dt

    # Print current position and speed
    print('x: %.2f, y: %.2f, speed: %.2f' % (x, y, speed))
