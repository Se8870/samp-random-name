/*
    random-names.inc
    By: Kirima

    Original Code:
    https://github.com/treyhunner/names

    Always put original creators first!
    
*/

#if defined _INC_RANDOM_NAMES
    #endinput
#endif

#define _INC_RANDOM_NAMES

#if !defined _INC_SSCANF
    #error Include sscanf2 before random-names.inc, Link: https://github.com/Y-Less/sscanf
#endif

#if !defined NAME_PATH
    #define NAME_PATH               "names"
#endif

#if !defined MAX_RANDOM_NAMES
    #define MAX_RANDOM_NAMES        500
#endif

#define GENDER_NONE                 0
#define GENDER_MALE                 1
#define GENDER_FEMALE               2

static const STR_NULL[32] = '\1';

#if !defined _INC_y_core
stock Float:RandomFloat(Float:min, Float:max = Float:0x7FFFFFFF, dp = 2)
{
	new
		Float:mul = floatpower(10.0, float(dp));
	switch (dp)
	{
	case 0: mul = 1.0;
	case 1: mul = 10.0;
	case 2: mul = 100.0;
	case 3: mul = 1000.0;
	default: mul = floatpower(10.0, float(dp));
	}
	if (max != max)
	{
		if (min < 0.0)
			return -(float(random(floatround(-min * mul))) / mul);
		return float(random(floatround(min * mul))) / mul;
	}
	// Parameters are the wrong way around - do it anyway.
	if (max < min)
		return float(random(floatround(min * mul - max * mul))) / mul + max;
	// NOT a silly check - "IsNaN".
	return float(random(floatround(max * mul - min * mul))) / mul + min;
}

stock Random(min, max = cellmin)
{
	if (max == cellmin)
	{
		if (min < 0)
			return -random(-min);
		return random(min);
	}
	if (max < min)
		return random(min - max) + max;
	return random(max - min) + min;
}
#endif 

static __GetName(const filename[]) {
    if (!fexist(filename)) return STR_NULL;

    new 
        Float:selected = RandomFloat(0.0, 1.0) * 90,
        File: handl = fopen(filename);

    if (!handl) return STR_NULL;

    new strTemp[128];
    while(fread(handl, strTemp, sizeof strTemp)) {
        new name[32], Float:cummulative[2], ln;
        sscanf(strTemp, "s[32]ffi", name, cummulative[0], cummulative[1], ln);
        if (cummulative[1] > selected)
            return name;
    }
    return STR_NULL;
}

static __Capitalize(const str[]) {
    new ret[32];
    
    for (new i = 0, j = strlen(str); i < j; i ++) {
        ret[i] = tolower(str[i]);
    }
    ret[0] = str[0];
    return ret;
}

stock GetFirstName(gender = GENDER_NONE) {
    new ret[32];
    
    if (gender == GENDER_NONE) {
        gender = Random(GENDER_MALE, GENDER_FEMALE);
    }
    
    if (gender == GENDER_MALE) {
        format(ret, sizeof ret, "%s", __Capitalize(__GetName(NAME_PATH"/dist.male.first")));
        return ret;
    }
    else if (gender == GENDER_FEMALE) {
        format(ret, sizeof ret, "%s", __Capitalize(__GetName(NAME_PATH"/dist.female.first")));
        return ret;
    }
    return STR_NULL;
}

stock GetLastName() {
    new ret[32];
    format(ret, sizeof ret, "%s", __Capitalize(__GetName(NAME_PATH"/dist.all.last")));
    return ret;
}

stock GetRandomName(gender = GENDER_NONE, bool:underscore = false) {
    new ret[32];
    format(ret, sizeof ret, "%s%c%s", GetFirstName(gender), (underscore ? '_' : ' '), GetLastName());
    return ret;
}
