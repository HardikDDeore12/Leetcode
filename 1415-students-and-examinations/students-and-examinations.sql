SELECT st.student_id, st.student_name, su.subject_name, Count(e.subject_name) AS attended_exams
FROM Students st
CROSS Join Subjects su
LEFT Join Examinations e on st.student_id = e.student_id And su.subject_name = e.subject_name
Group by su.subject_name,st.student_name, su.subject_name
order by st.student_id, su.subject_name