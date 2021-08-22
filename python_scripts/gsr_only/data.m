clear all; close all; clc;

dt = importdata("assessment_centre.csv");
time = dt.textdata(2:end, 1);
time = datenum(time, 'HH:MM:SS');
time_seconds = dt.data(:, 1); %seconds
serial = dt.data(:, 2);
resistance = dt.data(:, 3);

cleaned_time = time([1:3773 3989:end]);
cleaned_serial = serial([1:3773 3989:end]);
cleaned_resistance = resistance([1:3773 3989:end]);

% Schedule
t1 = "8:30:00"; % Introduction
t2 = "9:10:00"; % Questions
t3 = "9:30:00"; % Break
t4 = "9:45:00"; % Interview
t5 = "11:00:00"; % Group Assessment Prep
t6 = "11:10:00"; % Group Asessment Reading Time
t7 = "11:20:00"; % Group Asessment Discussion
t8 = "11:45:00"; % Group Asessment Presentation
t9 = "11:55:00"; % Group Asessment Q&A

t1 = datenum(t1, 'HH:MM:SS');
t2 = datenum(t2, 'HH:MM:SS');
t3 = datenum(t3, 'HH:MM:SS');
t4 = datenum(t4, 'HH:MM:SS');
t5 = datenum(t5, 'HH:MM:SS');
t6 = datenum(t6, 'HH:MM:SS');
t7 = datenum(t7, 'HH:MM:SS');
t8 = datenum(t8, 'HH:MM:SS');
t9 = datenum(t9, 'HH:MM:SS');

plot(time, serial);
datetick('x', 'HH:MM:SS', 'keeplimits')
title('Serial data')
xlabel('Time (HH:MM:SS)')
ylabel('Sensor reading')
saveas(gcf, 'assessment_centre.png')


figure
plot(cleaned_time, cleaned_serial)
datetick('x', 'HH:MM:SS', 'keeplimits')
title('Cleaned Serial data')
xlabel('Time (HH:MM:SS)')
ylabel('Sensor reading')
xline(t1, '--b', {'Introduction'}, 'fontsize', 8)
xline(t2, '--b', {'Questions'}, 'fontsize', 8)
xline(t3, '--b', {'Break'}, 'fontsize', 8)
xline(t4, '--b', {'Interview'}, 'fontsize', 8)
xline(t5, '--b', {'GA Prep'}, 'fontsize', 8)
xline(t6, '--b', {'GA Reading'}, 'fontsize', 8)
xline(t7, '--b', {'GA Discussion'}, 'fontsize', 8)
xline(t8, '--b', {'GA Presentation'}, 'fontsize', 8)
xline(t9, '--b', {'GA Q&A'}, 'fontsize', 8)
saveas(gcf, 'assessment_centre_cleaned.png')


