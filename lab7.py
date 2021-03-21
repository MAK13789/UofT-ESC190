energies = [[24,      22,      30,      15,      18,      19],
            [12,      23,      15,      23,      10,     15],
            [11,      13,      22,      13,      21,      14],
            [13,      15,      17,      28,      19,      21],
            [17,      17,      7,       27,      20,      19]]
def seam(energies, cur_index):
    if len(energies) == 1:
        return min(energies[0])
    options = {}
    options[cur_index] = energies[0][cur_index] + seam(energies[1:], cur_index)
    if cur_index - 1 >= 0:
        options[cur_index-1] = energies[0][cur_index-1] + seam(energies[1:], cur_index-1)
    if cur_index + 1 <= len(energies[0]) - 1:
        options[cur_index+1] = energies[0][cur_index+1] + seam(energies[1:], cur_index+1)
    best_idx = min(options, key=options.get)
    return (energies[0][best_idx] + seam(energies[1:], best_idx))
seams = []
for i in range(len(energies[0])):
    temp = seam(energies, i)
    seams.append(temp)
print (min(seams))