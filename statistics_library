def mean(points):
    return sum(points) / len(points)


def median(points):
    points.sort()
    if len(points) % 2 != 0:
        return points[len(points) // 2]

    elif len(points) % 2 == 0:
        mid = len(points) // 2
        avg = (points[mid - 1] + points[mid]) / 2
        return avg


def mode(points):
    counts = {}
    for point in points:
        try:
            counts[point] += 1
        except KeyError:
            counts[point] = 1

    counts = sorted(counts.items(), key=lambda x: x[1])

    return counts[-1][0]


def population_variance(points):
    return sum((x - mean(points))**2 for x in points) / len(points)


def population_standard_deviation(points):
    return population_variance(points) ** 0.5


def sample_variance(points):
    return sum((x - mean(points))**2 for x in points) / (len(points) - 1)


def sample_standard_deviation(points):
    return sample_variance(points) ** 0.5


def stat_range(points):
    return max(points) - min(points)


def mean_abs_deviation(points):
    return sum(abs(x - mean(points)) for x in points) / len(points)


def z_score(point, points):
    return (point - mean(points)) / population_standard_deviation(points)


def z_transform(points):
    new_data = []
    for point in points:
        new_data.append(z_score(point, points))

    return new_data
