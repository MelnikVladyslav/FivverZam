update objects set deleted = 1 where x=0 and y=0 and z=0 and contained_by = 0 and deleted = 0 and scene_id <> 'universe';
