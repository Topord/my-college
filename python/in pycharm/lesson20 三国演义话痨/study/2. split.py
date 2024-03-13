line = 'alt="北京大学" width="164" height="60">'
print(line)
print(len(line))
print(type(line))
if "alt" in line:
    end = line.split("alt=")[-1]
print(end)
print(len(end))
print(type(end))
end = end.split('"')
print(end)
print(len(end))
print(type(end))
