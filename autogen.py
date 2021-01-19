import os
import glob

HEADER_NAME = 'ledfx_effects.h'

def get_filename(path):
    return os.path.basename(path).split('.')[0]

if __name__ == '__main__':
    print('Generating header with all effects')

    with open(HEADER_NAME, 'w') as header:
        # Add header guard
        header.write('#ifndef __LEDFX_EFFECTS_H__\n#define __LEDFX_EFFECTS_H__\n\n')

        # Add includes with configs
        effects = glob.glob('effects/*.h')
        for f in effects:
            header.write(f'#include <{f}>\n')

        # Total number of configs
        header.write(f'\n#define CONFIGS_SIZE {len(effects)}\n\n')

        # Add list of references to configs
        header.write('static void (*effect_ptr[CONFIGS_SIZE])() = {\n')
        for f in effects:
            header.write(f'    &{get_filename(f)},\n')
        header.write('};\n\n')

        # Close header guard
        header.write('#endif // __LEDFX_EFFECTS_H__\n')
