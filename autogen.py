import glob

HEADER_NAME = 'ledfx_effects.h'

if __name__ == '__main__':
    print('Generating header with all effects')

    with open(HEADER_NAME, 'w') as header:
        header.write('#ifndef __LEDFX_EFFECTS_H__\n#define __LEDFX_EFFECTS_H__\n\n')

        effects = glob.glob('effects/*.h')
        for f in effects:
            header.write(f'#include <{f}>\n')

        header.write(f'\n#define MAX_CONFIGS {len(effects)}\n\n')

        header.write('#endif // __LEDFX_EFFECTS_H__\n')
